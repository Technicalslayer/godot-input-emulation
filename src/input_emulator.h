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

	// void print_type(const Variant &p_variant) const;

	void move_mouse(Vector2 move_vector);
	void click_mouse();
	void single_key_press_and_release(int virtual_key);
	// void sdl_key_input();
	// void sdl_single_key_press(int virtual_key);
	// void sdl_single_key_release(int virtual_key);
	// bool sdl_gamepad_events_enabled();
};
