#pragma once
#include "../Math/Ray.h"
#include "../Math/Color.h"
class Material
{
public:
	virtual bool Scatter(const Ray& ray, const RayHit& hit, color3& attenuation, Ray& scattered) const = 0;

    virtual color3 GetEmissive() { return{ 0,0,0 }; }
};

class Lambertian : public Material
{
public:
    Lambertian(const color3& albedo) : m_albedo{ albedo } {}
    virtual bool Scatter(const Ray& ray, const RayHit& hit, color3& attenuation, Ray& scattered) const override;

protected:
    color3 m_albedo;
};


class Emissive : public Material
{
public:
    Emissive(const color3& albedo) : m_albedo{ albedo } {}
    bool Scatter(const Ray& ray, const RayHit& hit, color3& attenuation, Ray& scattered) const override
    {
        return false;
    }

    color3 GetEmissive() override { return m_albedo; }

protected:
    color3 m_albedo;
};

class Dilectric : public Material
{
public:
    Dilectric(const color3& albedo, float index = 0) : m_albedo{ albedo }, m_index{ index } {}
    virtual bool Scatter(const Ray& ray, const RayHit& hit, color3& attenuation, Ray& scattered) const override;

protected:
    color3 m_albedo;
    float m_index;
};
class Metal : public Material
{
public:
    Metal(const color3& albedo, float fuzz = 0) : m_albedo{ albedo }, m_fuzz{fuzz} {}
    virtual bool Scatter(const Ray& ray, const RayHit& hit, color3& attenuation, Ray& scattered) const override;

protected:
    color3 m_albedo;
    float m_fuzz;
};
