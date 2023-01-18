# Makefile
DIR = `basename $(CURDIR)`
# Kompilator g++.
CC = g++
# Mozliwe dodatkowe zmienne
# LIBS = -ll -lm
LIBS =
CFLAGS = -Wall -std=c++11
# Pliki obiektowe - powstaja z plikow *.cpp.
OBJECTS = main.o
# Pliki naglowkowe - sa wlaczane do plikow *.cpp.
HFILES = graham.h point.h read_from_file.h write_to_file.h
# Plik wynikowy
OUTFILE = convex_hull_points.txt
# Koncowy plik wykonywalny.
TARGET = main.out

# Definicja domyslnej reguly wzorcowej.
# $< oznacza nazwe pliku pierwszej zaleznosci reguly.
# $@ oznacza nazwe pliku celu w regule.
# Wszystkie pliki obiektowe zaleza od wszystkich plikow naglowkowych.
%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

# Okreslenie celow sztucznych.
.PHONY : clean

clean :
	$(RM) $(OUTFILE) $(TARGET) *.o core
#==========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#==========================================================================