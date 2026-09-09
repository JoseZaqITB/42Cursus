class Plant:

    class _Statistics:
        def __init__(self):
            self._grow_calls: int = 0
            self._show_calls: int = 0
            self._age_calls: int = 0

        def display(self):
            print("Stats:", self._grow_calls, "grow,", self._age_calls,
                  "age,", self._show_calls, "show")

    def __init__(self, name: str, height: float, age: int, grow_scale: int):
        self._name = name
        self._height = 0
        self._age = 0
        self._statistics = self._Statistics()

        self.set_height(height)
        self.set_age(age)
        if grow_scale > 1:
            self.grow_scale = grow_scale
        else:
            self.grow_scale = 1

    def show(self):
        self._statistics._show_calls += 1
        print(self._name.capitalize()+":",
              round(self._height, 2), "cm,",
              self._age, "days old")

    def grow(self):
        self._height = round(self._height * self.grow_scale, 1)
        self._statistics._grow_calls += 1

    def age(self):
        self._age += 1
        self._statistics._age_calls += 1

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

    @staticmethod
    def is_old(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0, 1.0)


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
            print(self._name, " is blooming beautifully!")
        else:
            print(self._name, " has not bloomed yet")


class Seed(Flower):
    def __init__(self, name, height, age, grow_scale, color):
        super().__init__(name, height, age, grow_scale, color)
        self._seed_count = 0

    def bloom(self) -> None:
        super().bloom()
        self._seed_count += 42

    def age(self, days: int) -> None:
        super().age()
        self._age += days - 1

    def show(self) -> None:
        super().show()
        print(" Seeds:", self._seed_count)


class Tree(Plant):
    class _TreeStatistics(Plant._Statistics):
        def __init__(self):
            super().__init__()
            self._shade_calls = 0

        def display(self) -> None:
            super().display()
            print(" ", self._shade_calls, "shade")

    def __init__(self, name: str, height: float, age: int,
                 grow_scale: float, trunk_diameter: float):
        super().__init__(name, height, age, grow_scale)
        self._statistics: "Tree._TreeStatistics" = self._TreeStatistics()
        self.set_trunk_diameter(trunk_diameter)

    def set_trunk_diameter(self, trunk_diameter: float) -> None:
        self._trunk_diameter = trunk_diameter

    def get_trunk_diameter(self) -> float:
        return self._trunk_diameter

    def produce_shade(self) -> None:
        self._statistics._shade_calls += 1
        print("Tree Oak now produces a shade of",
              self._height, "cm long and ", self._trunk_diameter, "cm wide.")

    def show(self) -> None:
        super().show()
        print(" Trunk diameter:", self._trunk_diameter, "cm")


def display_plant_statistics(plant: Plant) -> None:
    plant._statistics.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print("Is 30 days more than a year? ->", Plant.is_old(30))
    print("Is 400 days more than a year? ->", Plant.is_old(400))

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, 1.1, "Red")
    rose.show()
    display_plant_statistics(rose)
    rose.grow()
    rose.bloom()
    rose.show()
    display_plant_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 1.25, 5.0)
    oak.show()
    display_plant_statistics(oak)
    oak.produce_shade()
    display_plant_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, 1.375, "yellow")
    sunflower.show()
    sunflower.grow()
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    display_plant_statistics(sunflower)

    print("\n=== Anonymous")
    unknown = Plant.anonymous()
    unknown.show()
    display_plant_statistics(unknown)
