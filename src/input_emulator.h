#pragma once

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class InputEmulator : public RefCounted {
	GDCLASS(InputEmulator, RefCounted)

protected:
	static void _bind_methods();

public:
	InputEmulator() = default;
	~InputEmulator() override = default;

	void print_type(const Variant &p_variant) const;
};
