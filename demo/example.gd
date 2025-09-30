extends Node

var inputEmu

func _ready() -> void:
	inputEmu = InputEmulator.new()
	#example.print_type(example)
	#
	#example.move_mouse(Vector2.ONE * 100.0)
	

func _process(delta):
	if Input.is_joy_button_pressed(0, JOY_BUTTON_A):
		inputEmu.single_key_press_and_release(0x041)
