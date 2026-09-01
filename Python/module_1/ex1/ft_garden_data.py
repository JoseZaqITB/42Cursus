class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(self.name.capitalize()+":",
              self.height, "cm,",
              self.age, "days old")


if __name__ == "__main__":
    plant1 = Plant("Rosa", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    print("=== Garden Plant Registry ===")
    plant1.show()
    plant2.show()
    plant3.show()
