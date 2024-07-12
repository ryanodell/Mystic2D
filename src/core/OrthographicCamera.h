#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H
#include "../GLM/glm.hpp"
#include <../GLM/gtc/matrix_transform.hpp>

namespace Mystic {
class OrthographicCamera {
   public:
    OrthographicCamera() {}
    ~OrthographicCamera() {}
    OrthographicCamera(float left, float right, float bottom, float top, float zoom = 1.0f);
    void UpdateProjection(float left, float right, float bottom, float top);

    const glm::vec3 GetPosition() const { return m_position; }
    void SetPosition(const glm::vec3& positon) {
        m_position = positon;
        recalculateViewMatrix();
    }

    const float GetRotation() const { return m_rotation; }

    const glm::mat4& GetProjectionMatrix() const { return m_projectionMatrix; }
    const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
    const glm::mat4& GetViewProjectionMatrix() const { return m_viewProjectionMatrix; }

   private:
    void recalculateViewMatrix();
    void applyZoomToProjection();

    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    // For caching the calculation:
    glm::mat4 m_viewProjectionMatrix;

    glm::vec3 m_position = {0.0f, 0.0f, 0.0f};

    //Not using this, just putting it here in case I change my mind
    float m_rotation = 0.0f;
    float m_zoom = 1.0f;
    float m_left, m_right, m_bottom, m_top;
};

}  // namespace Mystic

#endif
