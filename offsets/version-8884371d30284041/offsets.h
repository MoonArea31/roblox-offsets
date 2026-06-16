#pragma once
#include <cstdint>

// version-8884371d30284041
// dumped by moon (discord.gg/skids <- pls join)

namespace offsets {
    inline constexpr const char* roblox_version = "version-8884371d30284041";

    namespace VisualEngine {
        inline constexpr uintptr_t ViewMatrix = 0x150;
        inline constexpr uintptr_t RenderView = 0xbb8;
        inline constexpr uintptr_t Pointer = 0x82ea3f8;
        inline constexpr uintptr_t FakeDataModel = 0x1d8;
    }

    namespace DataModel {
        inline constexpr uintptr_t PlaceId = 0x1a8;
        inline constexpr uintptr_t GameId = 0x1a0;
        inline constexpr uintptr_t CreatorId = 0x198;
        inline constexpr uintptr_t Workspace = 0x178;
        inline constexpr uintptr_t ServerIP = 0x660;
        inline constexpr uintptr_t ScriptContext = 0x430;
        inline constexpr uintptr_t JobId = 0x138;
    }

    namespace Instance {
        inline constexpr uintptr_t Parent = 0x70;
        inline constexpr uintptr_t ClassDescriptor = 0x18;
        inline constexpr uintptr_t ChildrenStart = 0x78;
        inline constexpr uintptr_t ChildrenEnd = 0x8;
        inline constexpr uintptr_t Name = 0xb0;
        inline constexpr uintptr_t ClassName = 0x8;
    }

    namespace Player {
        inline constexpr uintptr_t LocalPlayer = 0x148;
        inline constexpr uintptr_t ModelInstance = 0x3d0;
        inline constexpr uintptr_t UserId = 0x2f8;
        inline constexpr uintptr_t DisplayName = 0x150;
        inline constexpr uintptr_t TeamColor = 0x398;
        inline constexpr uintptr_t Team = 0x2d0;
        inline constexpr uintptr_t CameraMaxZoomDist = 0x354;
        inline constexpr uintptr_t CameraMinZoomDist = 0x358;
    }

    namespace BasePart {
        inline constexpr uintptr_t Primitive = 0x148;
        inline constexpr uintptr_t Reflectance = 0xec;
        inline constexpr uintptr_t Color3 = 0x194;
        inline constexpr uintptr_t Transparency = 0xf0;
        inline constexpr uintptr_t CastShadow = 0xf5;
        inline constexpr uintptr_t Locked = 0xf6;
        inline constexpr uintptr_t Massless = 0xf7;
    }

    namespace Primitive {
        inline constexpr uintptr_t Position = 0xec;
        inline constexpr uintptr_t CFrame = 0xc8;
        inline constexpr uintptr_t Rotation = 0xc8;
        inline constexpr uintptr_t Size = 0x1b8;
        inline constexpr uintptr_t AssemblyLinearVelocity = 0xf8;
        inline constexpr uintptr_t AssemblyAngularVelocity = 0x104;
        inline constexpr uintptr_t Material = 0x23e;
        inline constexpr uintptr_t Shape = 0x1b1;
        inline constexpr uintptr_t PrimitiveFlags = 0x1b6;
        inline constexpr uintptr_t Owner = 0x208;
    }

    namespace Humanoid {
        inline constexpr uintptr_t CameraOffset = 0x140;
        inline constexpr uintptr_t UseJumpPower = 0x1ec;
        inline constexpr uintptr_t AutoJumpEnabled = 0x1e0;
        inline constexpr uintptr_t Health = 0x194;
        inline constexpr uintptr_t MaxHealth = 0x1b4;
        inline constexpr uintptr_t WalkSpeed = 0x1dc;
        inline constexpr uintptr_t WalkSpeedCheck = 0x3c4;
        inline constexpr uintptr_t JumpPower = 0x1b0;
        inline constexpr uintptr_t JumpHeight = 0x1ac;
        inline constexpr uintptr_t HipHeight = 0x1a0;
        inline constexpr uintptr_t HealthDisplayDistance = 0x198;
        inline constexpr uintptr_t MaxSlopeAngle = 0x1b8;
        inline constexpr uintptr_t NameDisplayDistance = 0x1bc;
        inline constexpr uintptr_t WalkToPoint = 0x17c;
        inline constexpr uintptr_t FloorMaterial = 0x190;
        inline constexpr uintptr_t WalkTimer = 0x410;
        inline constexpr uintptr_t WalkToPart = 0x130;
        inline constexpr uintptr_t AutoRotate = 0x1e1;
        inline constexpr uintptr_t Sit = 0x1ea;
        inline constexpr uintptr_t BreakJointsOnDeath = 0x1e3;
        inline constexpr uintptr_t RequiresNeck = 0x1e9;
        inline constexpr uintptr_t EvaluateStateMachine = 0x1e4;
        inline constexpr uintptr_t RigType = 0x1cc;
        inline constexpr uintptr_t TargetPoint = 0x164;
        inline constexpr uintptr_t HumanoidState = 0x8a8;
        inline constexpr uintptr_t HumanoidStateID = 0x20;
    }

    namespace Lighting {
        inline constexpr uintptr_t Sky = 0x1e0;
        inline constexpr uintptr_t ClockTime = 0x1c0;
        inline constexpr uintptr_t Ambient = 0xe0;
        inline constexpr uintptr_t EnvironmentDiffuseScale = 0x12c;
        inline constexpr uintptr_t Atmosphere = 0x1f0;
        inline constexpr uintptr_t EnvironmentSpecularScale = 0x130;
        inline constexpr uintptr_t OutdoorAmbient = 0x110;
        inline constexpr uintptr_t ColorShift_Bottom = 0xf8;
        inline constexpr uintptr_t ColorShift_Top = 0xec;
    }

    namespace LightingParameters {
        inline constexpr uintptr_t GeographicLatitude = 0x198;
    }

    namespace World {
        inline constexpr uintptr_t FallenPartsDestroyHeight = 0x208;
        inline constexpr uintptr_t Gravity = 0x210;
        inline constexpr uintptr_t WorldStepPerSec = 0x680;
        inline constexpr uintptr_t Primitives = 0x288;
    }

    namespace Workspace {
        inline constexpr uintptr_t World = 0x400;
        inline constexpr uintptr_t ReadOnlyGravity = 0x9e8;
        inline constexpr uintptr_t CurrentCamera = 0x4a8;
    }

    namespace VectorForce {
        inline constexpr uintptr_t ApplyAtCenterOfMass = 0x1a0;
        inline constexpr uintptr_t Force = 0x190;
        inline constexpr uintptr_t RelativeTo = 0x19c;
    }

    namespace DragDetector {
        inline constexpr uintptr_t Enabled = 0xdf;
        inline constexpr uintptr_t RunLocally = 0xe1;
        inline constexpr uintptr_t MaxDragTranslation = 0x284;
        inline constexpr uintptr_t MinDragTranslation = 0x290;
        inline constexpr uintptr_t MaxForce = 0x2c4;
        inline constexpr uintptr_t Responsiveness = 0x2d8;
        inline constexpr uintptr_t DragStyle = 0x2b4;
    }

    namespace Terrain {
        inline constexpr uintptr_t WaterColor = 0x1e0;
        inline constexpr uintptr_t WaterReflectance = 0x1f8;
        inline constexpr uintptr_t WaterTransparency = 0x1fc;
        inline constexpr uintptr_t WaterWaveSize = 0x200;
        inline constexpr uintptr_t WaterWaveSpeed = 0x204;
        inline constexpr uintptr_t GrassLength = 0x1f0;
    }

    namespace Camera {
        inline constexpr uintptr_t DiagonalFieldOfView = 0x15c;
        inline constexpr uintptr_t MaxAxisFieldOfView = 0x15c;
        inline constexpr uintptr_t FieldOfView = 0x160;
        inline constexpr uintptr_t Position = 0x11c;
        inline constexpr uintptr_t CFrame = 0xf8;
        inline constexpr uintptr_t ViewportInt16 = 0x2ac;
        inline constexpr uintptr_t ViewportSize = 0x2e8;
        inline constexpr uintptr_t CameraSubject = 0xe8;
        inline constexpr uintptr_t CameraType = 0x158;
    }

    namespace Script {
        inline constexpr uintptr_t RequireBypass = 0x0;
    }

    namespace Players {
        inline constexpr uintptr_t RespawnTime = 0x160;
    }

    namespace Model {
        inline constexpr uintptr_t PrimaryPart = 0x278;
        inline constexpr uintptr_t Scale = 0x164;
    }

    namespace Tool {
        inline constexpr uintptr_t CanBeDropped = 0x4c0;
        inline constexpr uintptr_t Enabled = 0x4c1;
        inline constexpr uintptr_t ManualActivationOnly = 0x4c2;
        inline constexpr uintptr_t RequiresHandle = 0x4c3;
        inline constexpr uintptr_t Tooltip = 0x470;
        inline constexpr uintptr_t Grip = 0x490;
        inline constexpr uintptr_t GripRight = 0x490;
        inline constexpr uintptr_t GripUp = 0x49c;
        inline constexpr uintptr_t GripForward = 0x4a8;
        inline constexpr uintptr_t GripPos = 0x4b4;
    }

    namespace ProximityPrompt {
        inline constexpr uintptr_t ActionText = 0xc8;
        inline constexpr uintptr_t ObjectText = 0xe8;
        inline constexpr uintptr_t HoldDuration = 0x138;
        inline constexpr uintptr_t MaxActivationDistance = 0x140;
        inline constexpr uintptr_t KeyboardKeyCode = 0x13c;
        inline constexpr uintptr_t Enabled = 0x14e;
        inline constexpr uintptr_t RequiresLineOfSight = 0x14f;
    }

    namespace ClickDetector {
        inline constexpr uintptr_t MaxActivationDistance = 0x100;
    }

    namespace Misc {
        inline constexpr uintptr_t Value = 0xd0;
        inline constexpr uintptr_t StatsItemValue = 0xd0;
    }

    namespace PrimitiveFlags {
        inline constexpr uintptr_t Anchored = 0x2;
        inline constexpr uintptr_t CanCollide = 0x8;
        inline constexpr uintptr_t CanTouch = 0x10;
        inline constexpr uintptr_t CanQuery = 0x20;
    }

    namespace FakeDataModel {
        inline constexpr uintptr_t Pointer = 0x7bcf6a8;
        inline constexpr uintptr_t RealDataModel = 0x1d8;
    }

    namespace GuiObject {
        inline constexpr uintptr_t Visible = 0x5ad;
        inline constexpr uintptr_t ZIndex = 0x5a4;
        inline constexpr uintptr_t BackgroundColor3 = 0x540;
        inline constexpr uintptr_t BackgroundTransparency = 0x564;
        inline constexpr uintptr_t BorderSizePixel = 0x56c;
    }

    namespace TextLabel {
        inline constexpr uintptr_t Text = 0xb50;
        inline constexpr uintptr_t TextColor3 = 0xe50;
        inline constexpr uintptr_t TextSize = 0xe7c;
        inline constexpr uintptr_t TextTransparency = 0xe84;
    }

    namespace Attachment {
        inline constexpr uintptr_t WorldCFrame = 0xb8;
        inline constexpr uintptr_t WorldAxis = 0xd0;
        inline constexpr uintptr_t WorldSecondaryAxis = 0xe8;
        inline constexpr uintptr_t WorldPosition = 0xdc;
    }

    namespace Sound {
        inline constexpr uintptr_t SoundId = 0xe0;
        inline constexpr uintptr_t Volume = 0x148;
        inline constexpr uintptr_t PlaybackSpeed = 0x134;
        inline constexpr uintptr_t Looped = 0x155;
        inline constexpr uintptr_t LoopRegion = 0x110;
        inline constexpr uintptr_t PlaybackRegion = 0x118;
    }

    namespace BodyVelocity {
        inline constexpr uintptr_t MaxForce = 0x2a0;
        inline constexpr uintptr_t Velocity = 0x2ac;
        inline constexpr uintptr_t P = 0x2b8;
    }

    namespace LinearVelocity {
        inline constexpr uintptr_t MaxForce = 0x1b0;
        inline constexpr uintptr_t VectorVelocity = 0x264;
    }

    namespace ModuleScript {
        inline constexpr uintptr_t Bytecode = 0xc8;
        inline constexpr uintptr_t Hash = 0x160;
    }

    namespace LocalScript {
        inline constexpr uintptr_t Bytecode = 0x1a8;
    }

    namespace Bytecode {
        inline constexpr uintptr_t Size = 0x48;
        inline constexpr uintptr_t Pointer = 0x10;
    }

    namespace MeshData {
        inline constexpr uintptr_t FaceEnd = 0x38;
        inline constexpr uintptr_t FaceStart = 0x30;
        inline constexpr uintptr_t VertexEnd = 0x8;
        inline constexpr uintptr_t VertexStart = 0x0;
    }

    namespace MeshPart {
        inline constexpr uintptr_t MeshId = 0x2f8;
        inline constexpr uintptr_t Texture = 0x328;
    }
}
