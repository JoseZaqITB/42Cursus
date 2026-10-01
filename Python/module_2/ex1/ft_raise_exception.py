
def input_temperature(temp_str: str):
    temp: int = int(temp_str)
    max_degree: int = 40
    min_degree: int = 0

    if temp >= min_degree and temp <= max_degree:
        return temp
    elif temp >= max_degree:
        raise ValueError(
            f"{temp}°C is too hot for plants (max {max_degree}°C)"
            )
    else:
        raise ValueError(
            f"{temp}°C is too cold for plants (min {min_degree}°C)"
            )


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

    input = "100"
    print("\nInput data is", input)
    try:
        print("Temperature is now", input_temperature(input), "°C")
    except ValueError as error:
        print("Caught input_temperature error:", error)

    input = "-50"
    print("\nInput data is", input)
    try:
        print("Temperature is now", input_temperature(input), "°C")
    except ValueError as error:
        print("Caught input_temperature error:", error)

    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
