#include "Renderer3D.hpp"

namespace ee::renderer
{
    void Renderer3D::Init(int _width, int _height, const char* _title, int _targetFPS)
    {
        InitWindow(_width, _height, _title);
        SetTargetFPS(_targetFPS);

        m_camera.position   = { 5.0f, 5.0f, 5.0f };
        m_camera.target     = { 0.0f, 0.0f, 0.0f };
        m_camera.up         = { 0.0f, 1.0f, 0.0f };
        m_camera.fovy       = 45.0f;
        m_camera.projection = CAMERA_PERSPECTIVE;
    }

    void Renderer3D::BeginFrame()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
    }

    void Renderer3D::EndFrame()
    {
        EndDrawing();
    }

    void Renderer3D::BeginScene()
    {
        BeginMode3D(m_camera);
    }

    void Renderer3D::EndScene()
    {
        EndMode3D();
    }

    void Renderer3D::PushMatrix()
    {
        rlPushMatrix();
    }

    void Renderer3D::PopMatrix()
    {
        rlPopMatrix();
    }

    void Renderer3D::Translate(float _x, float _y, float _z)
    {
        rlTranslatef(_x, _y, _z);
    }

    void Renderer3D::Rotate(float _angle, float _x, float _y, float _z)
    {
        rlRotatef(_angle, _x, _y, _z);
    }

    void Renderer3D::Scale(float _x, float _y, float _z)
    {
        rlScalef(_x, _y, _z);
    }

    void Renderer3D::DrawBox(Vector3 _pos, Vector3 _size, Color _color)
    {
        DrawCube(_pos, _size.x, _size.y, _size.z, _color);
    }

    void Renderer3D::DrawBoxWires(Vector3 _pos, Vector3 _size, Color _color)
    {
        DrawCubeWires(_pos, _size.x, _size.y, _size.z, _color);
    }

    void Renderer3D::DrawGrid(int _slices, float _spacing)
    {
        ::DrawGrid(_slices, _spacing);
    }

    Model Renderer3D::LoadMesh(const char* _path)
    {
        return LoadModel(_path);
    }

    void Renderer3D::DrawMesh(Model& _model, Vector3 _pos, float _scale, Color _tint)
    {
        DrawModel(_model, _pos, _scale, _tint);
    }

    void Renderer3D::SetCameraPosition(Vector3 _pos)
    {
        m_camera.position = _pos;
    }

    void Renderer3D::SetCameraTarget(Vector3 _target)
    {
        m_camera.target = _target;
    }

    Camera3D& Renderer3D::GetCamera()
    {
        return m_camera;
    }

} // namespace ee::renderer
