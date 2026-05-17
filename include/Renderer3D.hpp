#pragma once

#include "raylib.h"
#include "rlgl.h"

namespace ee::renderer
{
    class Renderer3D
    {
    public:
        void Init(int _width, int _height, const char* _title, int _targetFPS = 60);

        // Frame
        void BeginFrame();
        void EndFrame();

        // Scene 3D
        void BeginScene();
        void EndScene();

        // Transformations
        void PushMatrix();
        void PopMatrix();
        void Translate(float _x, float _y, float _z);
        void Rotate(float _angle, float _x, float _y, float _z);
        void Scale(float _x, float _y, float _z);

        // Dessin primitives
        void DrawBox(Vector3 _pos, Vector3 _size, Color _color);
        void DrawBoxWires(Vector3 _pos, Vector3 _size, Color _color);
        void DrawGrid(int _slices, float _spacing);

        // Modeles (future)
        Model LoadMesh(const char* _path);
        void DrawMesh(Model& _model, Vector3 _pos, float _scale, Color _tint);

        // Camera
        void SetCameraPosition(Vector3 _pos);
        void SetCameraTarget(Vector3 _target);
        Camera3D& GetCamera();

    private:
        Camera3D m_camera = {};
    };

} // namespace ee::renderer
