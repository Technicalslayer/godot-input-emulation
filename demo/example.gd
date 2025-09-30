extends Node


func _ready() -> void:
	var example := InputEmulator.new()
	example.print_type(example)
	
	example.sdl_move_mouse(Vector2.ONE * 100.0)
