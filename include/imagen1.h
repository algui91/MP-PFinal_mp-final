/*
 * imagen1.h
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */

#ifndef IMAGEN1_H_
#define IMAGEN1_H_

class Imagen{

private:
	int filas;
	int columnas;
	unsigned char* buffer;

public:
	void crear(int, int);						//Reserva recursos en memoria dinámica
	int get_filas() const{				//Devuelve el número de filas de m
		return filas;
	}
	inline int get_columnas() const{			//Devuelve el número de columnas de m
		return columnas;
	}
	void set_buffer(int, int, unsigned char);	//Hace img(i,j)=v
	int get_buffer(int, int) const; 	//Devuelve img(i,j)
	void destruir();							//Libera recursos de m
	bool leer_imagen(const char[]);				//Carga imagen en img
	bool escribir_imagen(const char[]);	//Salva img en un archivo
};

#endif /* IMAGEN1_H_ */
