
struct WeaponData {
	float bulletSpeed;
	float bulletDamage;
	int bulletH, bulletW;
};

class Weapon {
	WeaponData config;
	float fireRate;
	float fireTimer;
public:
	bool canFire() { return fireTimer <= 0.0f; }

};