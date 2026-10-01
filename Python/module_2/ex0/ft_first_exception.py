
def input_temperature(temp_str: str):
    return int(temp_str)


def test_temperature():
    input = "25"
    print("=== Garden Temperature ===")
    print("Input data is", input)
    print("Temperature is now", input_temperature(input), "°C")

    input = "abc"
    print("\nInput data is", input)
    try:
        print("Temperature is now", input_temperature(input), "°C")
    except ValueError as error:
        print("Caught input_temperature error:", error)
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
