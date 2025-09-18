extends Node


func _ready() -> void:
	var example := InputEmulator.new()
	example.print_type(example)
