def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def print_recursive(day):
        if day > days:
            print("Harvest time!")
            return
        else:
            print("Day ", day)
            print_recursive(day + 1)

    print_recursive(1)
