#pragma once
#include <string>
#include <cstdint>
#include "../memory/memory.h" // your own memory library
#include "../memory/autoupdate.h" // THIS IS howtouseincpp.h

#define nil 0
struct Instance {
    uintptr_t address;
    Instance(uintptr_t addr = 0) : address(addr) {}

    mutable uintptr_t primitive = 0;
    mutable std::string cached_classname = "";

    uintptr_t get_primitive() const {
        if (!primitive) primitive = memory::read<uintptr_t>(address + offsets::BasePart::Primitive);
        return primitive;
    }
    
    inline std::string Name() const;
    inline std::string ClassName() const;

    std::vector<Instance> get_children() const;
    std::vector<Instance> get_descendants() const;
    Instance FindFirstChild(const std::string& name) const;
    Instance FindFirstChildWhichIsA(const std::string& name) const;
    Instance LocalPlayer() const;
    Instance Character() const;
    Instance Parent(uintptr_t type = -1) const;
    Instance GetService(const std::string& name) const;

    Vector3 Position(bool camera = false) const;
    Vector3 Size() const;    
    Vector3 Velocity() const;
    Vector3 SetPosition(Vector3 vec) const;
    Vector3 CameraPosition() const;
    Matrix3x3 get_rotation() const;

    // humanoid stuff lol
    float Health() const;
    float MaxHealth() const;

    bool IsSit() const;
    bool CanCollide() const;

    void set_rotation(Matrix3x3 matrix) const;
    void Kill() const;
    void WriteVelocity(Vector3 velocity) const;
    void WritePosition(Vector3 position) const;

    RBXCFrame get_cframe() const;
    void SetCanCollide(bool state) const;

    int64_t Address() {return address;}
    inline bool IsValid() {
        if (address == 0) return false;
        return true;
    }
};

namespace DataModel {
    static uintptr_t find() {
        uintptr_t fake = memory::read<uintptr_t>(memory::get_base() + offsets::FakeDataModel::Pointer);
        return memory::read<uintptr_t>(fake + offsets::FakeDataModel::RealDataModel);
    }

    static uintptr_t PlaceId() {
        return memory::read<uintptr_t>(find() + offsets::DataModel::PlaceId);
    }

    static uintptr_t CreatorId() {
        return memory::read<uintptr_t>(find() + offsets::DataModel::CreatorId);
    }
}
