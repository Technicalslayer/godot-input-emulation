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
	void left_click_mouse();
	void right_click_mouse();
	void left_mouse_down();
	void left_mouse_up();
	void right_mouse_down();
	void right_mouse_up();
	void mouse_scroll(int scroll_amount);
	void single_key_press_and_release(int virtual_key);
	// void sdl_key_input();
	void single_key_press(int virtual_key);
	void single_key_release(int virtual_key);
	// bool sdl_gamepad_events_enabled();
};
