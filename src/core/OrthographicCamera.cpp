#include "OrthographicCamera.h"

namespace Mystic {
OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float zoom)
    : m_left(left), m_right(right), m_bottom(bottom), m_top(top), m_zoom(zoom),
        m_projectionMatrix(glm::ortho(left / zoom, right / zoom, bottom / zoom, top / zoom, -1.0f, 1.0f)), m_viewMatrix(1.0f) {
    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
void OrthographicCamera::UpdateProjection(float left, float right, float bottom, float top) {
    m_projectionMatrix = glm::ortho(left / m_zoom, right / m_zoom , bottom / m_zoom, top / m_zoom, -1.0f, 1.0f);
    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
void OrthographicCamera::SetZoom(float zoom) {
    m_zoom = zoom;
    applyZoomToProjection();
}
void OrthographicCamera::recalculateViewMatrix() {
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
                          glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0, 0, 1));

    m_viewMatrix = glm::inverse(transform);
    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
void OrthographicCamera::applyZoomToProjection() {
    m_projectionMatrix = glm::ortho(m_left / m_zoom, m_right / m_zoom, m_bottom / m_zoom, m_top / m_zoom, -1.0f, 1.0f);
    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
}  // namespace Mystic