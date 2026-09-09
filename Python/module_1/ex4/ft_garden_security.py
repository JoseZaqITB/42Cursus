class Plant:
    def __init__(self, name: str, height: float, age: int, grow_scale: int):
        self._name = name
        self._height = 0
        self._age = 0

        self.set_height(height)
        self.set_age(age)
        if grow_scale > 1:
            self.grow_scale = grow_scale
        else:
            self.grow_scale = 1

    def show(self):
        print(self._name.capitalize()+":",
              round(self._height, 2), "cm,",
              self._age, "days old")

    def grow(self):
        self._height = round(self._height * self.grow_scale, 1)

    def age(self):
        self._age += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, height: float) -> None:
        if height < 0:
            print(self._name + ": Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(self._name + ": Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age


if __name__ == "__main__":
    plant = Plant("Rose", 15.0, 10, 1.1)
    print("Created: ", end="")
    plant.show()
    print("")
    plant.set_height(25.0)
    print("Height updated:", round(plant.get_height()), "cm")
    plant.set_age(30)
    print("Age updated:", plant.get_age(), "days")

    print("")
    plant.set_height(-1.0)
    plant.set_age(-10)

    print("")
    print("Current State: ", end="")
    plant.show()
