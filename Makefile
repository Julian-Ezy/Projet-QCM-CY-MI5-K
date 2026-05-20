CC = gcc

CFLAGS = -Wall -Wextra -Werror

TARGET = final

SRC = main.c \
      choix_utilisateur.c \
      creer_qcm1.c \
      creer_qcm2.c \
      enseignant_mdp.c \
      fonction_enseignant.c \
      fonction_etudiant.c \
      modif_mdp.c \
      parametre_menu.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c projet.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)