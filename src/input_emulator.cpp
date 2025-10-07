#include "input_emulator.h"
#include <Windows.h>

void InputEmulator::_bind_methods() {
	// godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &InputEmulator::print_type);

	ClassDB::bind_method(D_METHOD("mouse_move", "move_vector"), &InputEmulator::mouse_move);
	ClassDB::bind_method(D_METHOD("mouse_left_click"), &InputEmulator::mouse_left_click);
	ClassDB::bind_method(D_METHOD("mouse_right_click"), &InputEmulator::mouse_right_click);
	ClassDB::bind_method(D_METHOD("mouse_left_down"), &InputEmulator::mouse_left_down);
	ClassDB::bind_method(D_METHOD("mouse_left_up"), &InputEmulator::mouse_left_up);
	ClassDB::bind_method(D_METHOD("mouse_right_down"), &InputEmulator::mouse_right_down);
	ClassDB::bind_method(D_METHOD("mouse_right_up"), &InputEmulator::mouse_right_up);
	ClassDB::bind_method(D_METHOD("mouse_scroll", "scroll_amount"), &InputEmulator::mouse_scroll);
	
	// ClassDB::bind_method(D_METHOD("sdl_key_input"), &InputEmulator::sdl_key_input);
	ClassDB::bind_method(D_METHOD("single_key_press_and_release", "virutal_key"), &InputEmulator::single_key_press_and_release);
	ClassDB::bind_method(D_METHOD("single_key_press", "virtual_key"), &InputEmulator::single_key_press);
	ClassDB::bind_method(D_METHOD("single_key_release", "virtual_key"), &InputEmulator::single_key_release);
}

// void InputEmulator::print_type(const Variant &p_variant) const {
// 	print_line(vformat("Type: %d", p_variant.get_type()));
// }


void InputEmulator::mouse_move(Vector2 move_vector){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dx = move_vector.x; //x being coord in pixels
	input.mi.dy =  move_vector.y; //y being coord in pixels
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_left_click(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_right_click(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_left_down(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_left_up(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_right_down(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(input));
}

void InputEmulator::mouse_right_up(){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(input));
}

// Positive scroll_amount indicates a forward rotation, negative is backwards, towards user.
// One wheel click is defined as WHEEL_DELTA, which is 120
void InputEmulator::mouse_scroll(int scroll_amount){
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = scroll_amount;
	input.mi.dwFlags = MOUSEEVENTF_WHEEL;
	SendInput(1, &input, sizeof(input));
}

// find codes at: https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#extended-key-flag
void InputEmulator::single_key_press_and_release(int virtual_key){
	INPUT inputs[2] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = virtual_key;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = virtual_key;
	inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

}

void InputEmulator::single_key_press(int virtual_key){
	INPUT inputs[1] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = virtual_key;

	SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void InputEmulator::single_key_release(int virtual_key){
	INPUT inputs[1] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = virtual_key;
	inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}