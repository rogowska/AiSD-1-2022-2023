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
HFILES = doublelist.h
# Koncowy plik wykonywalny.
TARGET = zad05.out

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
	$(RM) $(TARGET) *.o core
#==========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#==========================================================================