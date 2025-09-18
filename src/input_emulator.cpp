#include "input_emulator.h"
#include <Windows.h>

void InputEmulator::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &InputEmulator::print_type);

	ClassDB::bind_method(D_METHOD("sdl_move_mouse", "move_vector"), &InputEmulator::sdl_move_mouse);
	ClassDB::bind_method(D_METHOD("sdl_click_mouse"), &InputEmulator::sdl_click_mouse);
	ClassDB::bind_method(D_METHOD("sdl_key_input"), &InputEmulator::sdl_key_input);
	ClassDB::bind_method(D_METHOD("sdl_single_key_press_and_release", "virutal_key"), &InputEmulator::sdl_single_key_press_and_release);
	ClassDB::bind_method(D_METHOD("sdl_single_key_press", "virtual_key"), &InputEmulator::sdl_single_key_press);
	ClassDB::bind_method(D_METHOD("sdl_single_key_release", "virtual_key"), &InputEmulator::sdl_single_key_release);
}

void InputEmulator::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}
