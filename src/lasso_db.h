#ifndef LASSO_DB_H
#define LASSO_DB_H

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

class LassoPoint;

class LassoDB : public RefCounted {
	GDCLASS(LassoDB, RefCounted);

	Array points;

public:
	LassoDB();
	~LassoDB();

	void add_point(Ref<LassoPoint> point);
	void remove_point(Ref<LassoPoint> point);
	Array calc_top_two_snapping_power(Transform3D source, Node *current_snap, float snap_max_power_increase, float snap_increase_amount, bool snap_lock);
	Node *calc_top_redirecting_power(Node *snapped_point, Transform3D viewpoint, Vector2 redirection_direction);

protected:
	static void _bind_methods();
};

#endif // LASSO_DB_H

