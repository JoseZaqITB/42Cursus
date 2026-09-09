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
    plant1 = Plant("Rosa", 25, 30, 1)
    plant2 = Plant("Sunflower", 80, 45, 1.1)
    plant3 = Plant("Cactus", 15, 120, 1.23)
    plant4 = Plant("Fern", 15, 120, 1.01)
    plant5 = Plant("oak", 15, 120, 1.5)

    print("=== Plant Factory Output ===")
    print("Created: ", end="")
    plant1.show()
    print("Created: ", end="")
    plant2.show()
    print("Created: ", end="")
    plant3.show()
    print("Created: ", end="")
    plant4.show()
    print("Created: ", end="")
    plant5.show()
