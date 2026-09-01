class Plant:
    def __init__(self, name: str, height: int, age: int, grow_scale: int):
        self.name = name
        self.height = height
        self._age = age
        if grow_scale > 1:
            self.grow_scale = grow_scale
        else:
            self.grow_scale = 1

    def show(self):
        print(self.name.capitalize()+":",
              self.height, "cm,",
              self._age, "days old")

    def grow(self):
        self.height = round(self.height * self.grow_scale, 1)

    def age(self):
        self._age += 1


if __name__ == "__main__":
    plant = Plant("Rose", 25, 30, 1.25)
    init_height = plant.height
    print("=== Garden Plant Growth ===")
    plant.show()

    for day in range(1, 8):
        print("=== Day", day, "===")
        plant.grow()
        plant.age()
        plant.show()
    growth = plant.height - init_height
    print("Growth this week: ", growth)
