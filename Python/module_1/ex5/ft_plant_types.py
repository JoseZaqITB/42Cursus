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


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 grow_scale: float, color: str):
        super().__init__(name, height, age, grow_scale)
        self.set_color(color)
        self._bloom: bool = False

    def set_color(self, color: str) -> None:
        self._color = color

    def get_color(self) -> str:
        return self._color

    def bloom(self) -> None:
        self._bloom = True

    def show(self) -> None:
        super().show()
        print(" Color: " + self._color)
        if self._bloom:
            print("Rose is blooming beautifully!")
        else:
            print("Rose has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 grow_scale: float, trunk_diameter: float):
        super().__init__(name, height, age, grow_scale)
        self.set_trunk_diameter(trunk_diameter)

    def set_trunk_diameter(self, trunk_diameter: float) -> None:
        self._trunk_diameter = trunk_diameter

    def get_trunk_diameter(self) -> float:
        return self._trunk_diameter

    def produce_shade(self) -> None:
        print("Tree Oak now produces a shade of",
              self._height, "cm long and ", self._trunk_diameter, "cm wide.")

    def show(self) -> None:
        super().show()
        print(" Trunk diameter:", self._trunk_diameter, "cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 grow_scale: float, harvest_season: str, nutritional_value: int
                 ):
        super().__init__(name, height, age, grow_scale)

        self._nutritional_value = 0
        self.set_harvest_season(harvest_season)
        self.set_nutritional_value(nutritional_value)
        self._increaseNutrition: int = 0

    def age(self):
        super().age()
        match self._increaseNutrition:
            case 0:
                self._increaseNutrition = 1
            case 1:
                self._nutritional_value += 1
                self._increaseNutrition = 0
            case _:
                self._increaseNutrition = 0

    def grow(self):
        super().grow()
        match self._increaseNutrition:
            case 0:
                self._increaseNutrition = 1
            case 1:
                self._nutritional_value += 1
                self._increaseNutrition = 0
            case _:
                self._increaseNutrition = 0

    def set_harvest_season(self, harvest_season: str) -> None:
        self._harvest_season = harvest_season

    def get_harvest_season(self) -> str:
        return self._harvest_season

    def set_nutritional_value(self, nutritional_value: int) -> None:
        self._nutritional_value = nutritional_value

    def get_nutritional_value(self) -> str:
        return self._nutritional_value

    def show(self) -> None:
        super().show()
        print(" Harvest season: ", self._harvest_season)
        print(" Nutritional value:", self._nutritional_value)


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 15.0, 10, 1.2, "red")
    flower.show()
    flower.bloom()
    flower.show()

    print("=== Tree")
    tree = Tree("Oak", 200.0, 365, 1.1, 5.0)
    tree.show()
    tree.produce_shade()

    print("=== Vegetable")
    vegetable = Vegetable("Tomato", 5.0, 10, 1.119, "April", 0)
    vegetable.show()
    for day in range(0, 20):
        vegetable.grow()
        vegetable.age()
    vegetable.show()
