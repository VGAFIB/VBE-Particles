#include "Fireball.hpp"
#include "PerspectiveCamera.hpp"
#include "ParticleSystem/FireParticleEmitter.hpp"
#include "ParticleSystem/MyParticleEmitter.hpp"

Fireball::Fireball() : pos(0.0f), vel(0.0f) {
	model.mesh = Meshes.get("fireballMesh");
	model.program = Programs.get("fireballShader");
	FireParticleEmitter* emitter = new FireParticleEmitter(200);
	emitter->addTo(this);
	MyParticleEmitter* emitter2 = new MyParticleEmitter(500);
	emitter2->addTo(this);
}

void Fireball::update(float deltaTime){
	(void) deltaTime;
	pos += vel*deltaTime;
	vel *= exp(-0.5*deltaTime);

	float angle = GLOBALCLOCK.getElapsedTime().asSeconds()*100;
	transform = mat4f(1.0f);
	transform = glm::translate(transform,pos);
	transform = glm::scale(transform,vec3f(0.7,0.7,0.7));
	transform = glm::rotate(transform,angle,vec3f(0,1,0));
}

void Fireball::draw() const {
	PerspectiveCamera* cam = static_cast<PerspectiveCamera*>(getGame()->getObjectByName("cam"));
	model.program->uniform("modelViewProjectionMatrix")->set(cam->projection*cam->view*fullTransform);
	model.program->uniform("sampler")->set(Textures.get("fireballTex"));
	model.draw();
}
