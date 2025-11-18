#ifndef LASSO_POINT_H
#define LASSO_POINT_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

// Forward declaration
class LassoDB;

class LassoPoint : public RefCounted {
	GDCLASS(LassoPoint, RefCounted);

	Node3D *origin = nullptr;
	float last_snap_score = 0.0;
	Ref<LassoDB> database;

public:
	float snapping_power = 1.0;
	bool snapping_enabled = true;
	bool snap_locked = true;
	float size = 0.3;

	LassoPoint();
	~LassoPoint();

	void register_point(Ref<LassoDB> p_database, Node *p_origin);
	void unregister_point();
	float get_snap_score();
	void set_snap_score(float score);
	Vector3 get_origin_pos();
	Node *get_origin();
	bool valid_origin();
	bool matching_origin(Node *p_origin);
	void enable_snapping(bool on);
	bool get_snapping_enabled();
	void set_snap_locked(bool p_enable);
	bool get_snap_locked();
	void set_size(float p_size);
	float get_size();
	void set_snapping_power(float p_snapping_power);
	float get_snapping_power();

protected:
	static void _bind_methods();
};

#endif // LASSO_POINT_H

