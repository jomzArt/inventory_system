inventory: inventory_system.o src/inventory_logic.o src/filter_inventory.o src/draw.o src/manage_data.o src/utility.o
	gcc inventory_system.o src/inventory_logic.o src/filter_inventory.o src/draw.o src/manage_data.o src/utility.o -o inventory

inventory_system.o: inventory_system.c include/helpers.h include/inventory.h
	gcc -c inventory_system.c -o inventory_system.o

src/inventory_logic.o: src/inventory_logic.c include/helpers.h include/inventory.h
	gcc -c src/inventory_logic.c -o src/inventory_logic.o

src/filter_inventory.o: src/filter_inventory.c include/helpers.h include/inventory.h
	gcc -c src/filter_inventory.c -o src/filter_inventory.o

src/draw.o: src/draw.c include/helpers.h include/inventory.h
	gcc -c src/draw.c -o src/draw.o

src/manage_data.o: src/manage_data.c include/helpers.h include/inventory.h
	gcc -c src/manage_data.c -o src/manage_data.o

src/utility.o: src/utility.c include/helpers.h include/inventory.h
	gcc -c src/utility.c -o src/utility.o

.PHONY: clean
clean:
	rm -f *.o src/*.o inventory.exe