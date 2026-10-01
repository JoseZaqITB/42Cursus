def garden_operations(operation_number: int):
    match operation_number:
        case 0:
            int("abc")
        case 1:
            10/0
        case 2:
            open("/nofileforthis.txt")
        case 3:
            "string" + 55
        case _:
            return


def test_error_types():
    operations = [0, 1, 2, 3, 4]

    for operation in operations:
        print(f"Testing operation {operation}...")
        try:
            garden_operations(operation)
            print("Operation completed successfully")
        except (ValueError, ZeroDivisionError, FileNotFoundError,
                TypeError) as e:
            print(f"Caught {type(e).__name__}: {e}")
        print("All error types tested successfully!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
