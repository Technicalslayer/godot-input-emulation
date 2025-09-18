#include "input_emulator.h"
#include <Windows.h>

void InputEmulator::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &InputEmulator::print_type);

	ClassDB::bind_method(D_METHOD("sdl_move_mouse", "move_vector"), &InputEmulator::sdl_move_mouse);
	ClassDB::bind_method(D_METHOD("sdl_click_mouse"), &InputEmulator::sdl_click_mouse);
	// ClassDB::bind_method(D_METHOD("sdl_key_input"), &InputEmulator::sdl_key_input);
	// ClassDB::bind_method(D_METHOD("sdl_single_key_press_and_release", "virutal_key"), &InputEmulator::sdl_single_key_press_and_release);
	// ClassDB::bind_method(D_METHOD("sdl_single_key_press", "virtual_key"), &InputEmulator::sdl_single_key_press);
	// ClassDB::bind_method(D_METHOD("sdl_single_key_release", "virtual_key"), &InputEmulator::sdl_single_key_release);
}

void InputEmulator::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}


void InputEmulator::sdl_move_mouse(Vector2 move_vector){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dx = move_vector.x; //x being coord in pixels
	input.mi.dy =  move_vector.y; //y being coord in pixels
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::sdl_click_mouse(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(input));
}