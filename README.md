# Godot Input Emulation
A GDExtension for Godot 4.5 that enables sending virtual keyboard and mouse inputs to the OS.
Currently only supports Windows.

## Usage - Template

To use this extension, simply drag and drop the unzipped folder to your 'addons' folder in the root of your Godot project. 
If your project was open, restart and the InputEmulator class should now be available.

## Documentation

### Functions

```
mouse_left_click()
mouse_left_down()
mouse_left_up()
mouse_move(move_vector: Vector2)
mouse_right_click()
mouse_right_down()
mouse_right_up()
mouse_scroll(scroll_amount: int)
single_key_press(virtual_key: int)
single_key_press_and_release(virtual_key: int)
single_key_release(virtual_key: int)
```

