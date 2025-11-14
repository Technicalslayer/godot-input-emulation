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

	void mouse_move(Vector2 move_vector);
	void mouse_left_click();
	void mouse_right_click();
	void mouse_left_down();
	void mouse_left_up();
	void mouse_right_down();
	void mouse_right_up();
	void mouse_scroll(int scroll_amount);
	void single_key_press_and_release(int virtual_key);
	void single_unicode_press_and_release(int unicode);
	// void sdl_key_input();
	void single_key_press(int virtual_key);
	void single_key_release(int virtual_key);
	int map_scan_code_to_virtual_key(int scan_code);
	int map_char_to_virtual_key(String character);
	int map_virtual_key_to_char(int virtual_key);
	
	// bool sdl_gamepad_events_enabled();
};
