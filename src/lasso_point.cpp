#include "lasso_point.h"
#include "lasso_db.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

LassoPoint::LassoPoint() {
}

LassoPoint::~LassoPoint() {
	unregister_point();
}

void LassoPoint::_bind_methods() {
	ClassDB::bind_method(D_METHOD("enable_snapping", "on"), &LassoPoint::enable_snapping);
	ClassDB::bind_method(D_METHOD("get_snapping_enabled"), &LassoPoint::get_snapping_enabled);
	ClassDB::bind_method(D_METHOD("set_snap_locked", "p_enable"), &LassoPoint::set_snap_locked);
	ClassDB::bind_method(D_METHOD("get_snap_locked"), &LassoPoint::get_snap_locked);
	ClassDB::bind_method(D_METHOD("set_size", "p_size"), &LassoPoint::set_size);
	ClassDB::bind_method(D_METHOD("get_size"), &LassoPoint::get_size);
	ClassDB::bind_method(D_METHOD("set_snapping_power", "p_snapping_power"), &LassoPoint::set_snapping_power);
	ClassDB::bind_method(D_METHOD("get_snapping_power"), &LassoPoint::get_snapping_power);
	ClassDB::bind_method(D_METHOD("get_snap_score"), &LassoPoint::get_snap_score);
	ClassDB::bind_method(D_METHOD("get_origin"), &LassoPoint::get_origin);
	ClassDB::bind_method(D_METHOD("register_point", "p_database", "p_origin"), &LassoPoint::register_point);
	ClassDB::bind_method(D_METHOD("unregister_point"), &LassoPoint::unregister_point);

	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "snapping_enabled"), "enable_snapping", "get_snapping_enabled");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "snap_locked"), "set_snap_locked", "get_snap_locked");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "size"), "set_size", "get_size");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "snapping_power"), "set_snapping_power", "get_snapping_power");
}

void LassoPoint::set_snap_locked(bool p_enable) {
	snap_locked = p_enable;
}

bool LassoPoint::get_snap_locked() {
	return snap_locked;
}

void LassoPoint::register_point(Ref<LassoDB> p_database, Node *p_origin) {
	database = p_database;
	origin = Object::cast_to<Node3D>(p_origin);
	ERR_FAIL_NULL(origin);
	ERR_FAIL_COND(database.is_null());
	database->add_point(this);
}

void LassoPoint::unregister_point() {
	if (database.is_valid()) {
		database->remove_point(this);
	}
	database.unref();
}

float LassoPoint::get_snap_score() {
	return last_snap_score;
}

void LassoPoint::set_snap_score(float score) {
	last_snap_score = score;
}

Vector3 LassoPoint::get_origin_pos() {
	if (origin != nullptr) {
		return origin->get_global_transform().origin;
	}
	return Vector3();
}

bool LassoPoint::valid_origin() {
	return origin != nullptr && origin->is_visible_in_tree() && snapping_enabled;
}

bool LassoPoint::matching_origin(Node *p_origin) {
	return origin == p_origin;
}

Node *LassoPoint::get_origin() {
	return origin;
}

void LassoPoint::enable_snapping(bool on) {
	snapping_enabled = on;
}

bool LassoPoint::get_snapping_enabled() {
	return snapping_enabled;
}

void LassoPoint::set_size(float p_size) {
	size = p_size;
}

float LassoPoint::get_size() {
	return size;
}

void LassoPoint::set_snapping_power(float p_snapping_power) {
	snapping_power = p_snapping_power;
}

float LassoPoint::get_snapping_power() {
	return snapping_power;
}

