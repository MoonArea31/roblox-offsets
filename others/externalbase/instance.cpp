#include "instance.h"

inline std::string Instance::Name() const {
    uintptr_t namePtr = memory::read<uintptr_t>(address + offsets::Instance::Name);
    if (!namePtr) {
        return "";
    }
    
    return memory::read_string(namePtr);
}

inline std::string Instance::ClassName() const {
    if (!cached_classname.empty()) return cached_classname;

    uintptr_t classdescriptor = memory::read<uintptr_t>(address + offsets::Instance::ClassDescriptor);
    uintptr_t classname = memory::read<uintptr_t>(classdescriptor + offsets::Instance::ClassName);
    cached_classname = memory::read_string(classname);
    return cached_classname;
}

std::vector<Instance> Instance::get_children() const {
    std::vector<Instance> container;
    
    uintptr_t startPointer = memory::read<uintptr_t>(address + offsets::Instance::ChildrenStart);
    if (!startPointer) return container;

    uintptr_t endPointer = memory::read<uintptr_t>(startPointer + offsets::Instance::ChildrenEnd);
    uintptr_t firstElement = memory::read<uintptr_t>(startPointer);

    if (endPointer <= firstElement) return container;

    size_t elementCount = (endPointer - firstElement) / 0x10;
    if (elementCount > 100000) return container;

    std::vector<ChildNode> childBuffer(elementCount);
    if (!memory::read_buffer<ChildNode>(firstElement, childBuffer.data(), elementCount))
        return container;

    for (const ChildNode& node : childBuffer) {
        if (node.instanceAddress) container.emplace_back(node.instanceAddress);
    }

    return container;
}

std::vector<Instance> Instance::get_descendants() const {
    std::vector<Instance> result;

    for (const Instance& child : get_children()) {
        result.push_back(child);

        std::vector<Instance> childDescendants = child.get_descendants();
        result.insert(result.end(), childDescendants.begin(), childDescendants.end());
    }

    return result;
}

Vector3 Instance::SetPosition(Vector3 vec) const {
    uintptr_t prim = get_primitive();
    if (!prim) return {};

    RBXCFrame cframe = memory::read<RBXCFrame>(prim + offsets::Primitive::CFrame);
    cframe.Position.x = vec.x;
    cframe.Position.y = vec.y;
    cframe.Position.z = vec.z;

    for (int i = 0; i < 1000; i++) memory::write<RBXCFrame>(prim + offsets::Primitive::CFrame, cframe);
    return vec;
}

Instance Instance::Parent(uintptr_t type) const {
    if (type == -1)
        return Instance(memory::read<uintptr_t>(address + offsets::Instance::Parent));

    memory::write<uintptr_t>(address + offsets::Instance::Parent, type);
    return Instance{ type };
}


Instance Instance::FindFirstChildWhichIsA(const std::string& name) const {
    for (const auto& child : get_children()) {
        if (child.ClassName() == name) return child;
    }
    return Instance(0);
}

Instance Instance::FindFirstChild(const std::string& name) const {
    for (const auto& child : get_children()) {
        if (child.Name() == name) return child;
    }
    return Instance(0);
}

Vector3 Instance::Position(bool camera) const {
    uintptr_t prim = get_primitive();
    if (!prim) return Vector3{};
    
    return memory::read<Vector3>(prim + offsets::Primitive::Position);
}

Vector3 Instance::Size() const {
    uintptr_t prim = get_primitive();
    if (!prim) return Vector3{};
    
    return memory::read<Vector3>(prim + offsets::Primitive::Size);
}

Instance Instance::LocalPlayer() const {
    std::vector<Instance> children = get_children();
    if (children.empty()) return {};
    return children[0];
}

Vector3 Instance::Velocity() const {
    uintptr_t prim = get_primitive();
    return memory::read<Vector3>(prim + offsets::Primitive::AssemblyLinearVelocity);
}

Instance Instance::GetService(const std::string& name) const {
    return FindFirstChild(name);
}

Instance Instance::Character() const {
    return Instance { memory::read<uintptr_t>(address + offsets::Player::ModelInstance) };
}

float Instance::Health() const {
    return memory::read<float>(address + offsets::Humanoid::Health);
}

float Instance::MaxHealth() const {
    return memory::read<float>(address + offsets::Humanoid::MaxHealth);
}

bool Instance::IsSit() const {
    return memory::read<bool>(address + offsets::Humanoid::Sit);
}

void Instance::Kill() const {
    std::string className = ClassName();
    if (className == "Humanoid") {
        memory::write<bool>(address + offsets::Humanoid::Health, 0);
        return;
    }

    else if (className == "ModuleScript" || className == "LocalScript")
    {
        uintptr_t msbytc = 0;
        if (className == "ModuleScript") msbytc = memory::read<uintptr_t>(address + offsets::ModuleScript::Bytecode);
        if (className == "LocalScript") msbytc = memory::read<uintptr_t>(address + offsets::LocalScript::Bytecode);
        if (!msbytc) return; // yes

        uintptr_t bytecodeptr = memory::read<uintptr_t>(msbytc + offsets::Bytecode::Pointer);
        uint64_t bytecodesize = memory::read<uint64_t>(msbytc + offsets::Bytecode::Size);
        if (bytecodesize == 0 || bytecodesize > 0x670000) return;

        std::vector<uint8_t> nullbytes(bytecodesize, 0);
        memory::write_buffer(bytecodeptr, nullbytes.data(), bytecodesize);
        memory::write<uint64_t>(msbytc + offsets::Bytecode::Size, 0);
        return;
    }
    
    else if (className == "Tool") 
    {
        RBXCFrame frame{};
        memory::write<bool>(address + offsets::Tool::Enabled, false);
        memory::write<bool>(address + offsets::Tool::CanBeDropped, false);
        memory::write<bool>(address + offsets::Tool::RequiresHandle, false);
        memory::write<bool>(address + offsets::Tool::ManualActivationOnly, false);
        memory::write<RBXCFrame>(address + offsets::Tool::Grip, frame);
        memory::write<float>(address + offsets::Model::Scale, 0); // i can do {} too
        memory::write<uintptr_t>(address + offsets::Instance::Parent, 0);
        return;
    }

    return;
}

void Instance::set_rotation(Matrix3x3 matrix) const {
    memory::write<Matrix3x3>(address + offsets::Camera::CFrame, matrix);
    return;
}

Vector3 Instance::CameraPosition() const {
    return memory::read<Vector3>(address + offsets::Camera::Position);
}

Matrix3x3 Instance::get_rotation() const {
    return memory::read<Matrix3x3>(address + offsets::Camera::CFrame);
}

void Instance::WriteVelocity(Vector3 velocity) const {
    uintptr_t primitive = get_primitive();
    for (int i = 0; i < 800; i++) memory::write<Vector3>(primitive + offsets::Primitive::AssemblyLinearVelocity, velocity);
    return;
}

RBXCFrame Instance::get_cframe() const {
    std::string className = ClassName();
    if (className == "Camera")
        return memory::read<RBXCFrame>(address + offsets::Camera::CFrame);
    else
        return memory::read<RBXCFrame>(get_primitive() + offsets::Primitive::CFrame);
}

bool Instance::CanCollide() const {
    uintptr_t primitive = get_primitive();
    BYTE flags = memory::read<BYTE>(primitive + offsets::Primitive::PrimitiveFlags);
    return (flags & offsets::PrimitiveFlags::CanCollide) != 0;
}


void Instance::SetCanCollide(bool state) const {
    uintptr_t primitive = get_primitive();
    BYTE flags = memory::read<BYTE>(primitive + offsets::Primitive::PrimitiveFlags);

    if (state) {
        flags |= offsets::PrimitiveFlags::CanCollide;
    }
    else {
        flags &= ~offsets::PrimitiveFlags::CanCollide;
    }

    memory::write<BYTE>(primitive + offsets::Primitive::PrimitiveFlags, flags);
    return;
}


void Instance::WritePosition(Vector3 position) const {
    uintptr_t prim = get_primitive();
    if (!prim) return;

    RBXCFrame cframe = memory::read<RBXCFrame>(prim + offsets::Primitive::CFrame);
    cframe.Position.x = position.x;
    cframe.Position.y = position.y;
    cframe.Position.z = position.z;

    for (int i = 0; i < 1000; i++) memory::write<RBXCFrame>(prim + offsets::Primitive::CFrame, cframe);
    return;
}
