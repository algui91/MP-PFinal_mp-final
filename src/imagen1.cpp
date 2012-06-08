/*
 * imagen1.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */
#include "../include/imagen1.h"
#include "../include/imagenES.h"

#include <assert.h>
#include <string.h>


void Imagen::crear(int f, int c) {
	//assert(f > 0 && c > 0);

	if (f > 0 && c > 0) {
		filas 	 = f;
		columnas = c;
		buffer   = new unsigned char[filas * columnas];
	} else {
		filas 	 = 0;
		columnas = 0;
		buffer	 = 0;
	}
}

void Imagen::set_buffer(int i, int j, unsigned char v) {
	buffer[i*columnas+j] = v;
}

//-------------------------

int Imagen::get_buffer(int i, int j) const {
	return buffer[i*columnas+j];
}

//-------------------------

void Imagen::destruir() {
	filas 		= 0;
	columnas	= 0;
	delete[] buffer;
}

//-------------------------

bool Imagen::leer_imagen(const char file[]) {
	int f;
	int c;
	bool resul = false;
	TipoImagen tipo = LeerTipoImagen(file, f, c);

	if (tipo == IMG_PGM) {
		destruir();
		crear(f, c);
		if (LeerImagenPGM(file, filas, columnas, buffer))
			resul = true;
	}
	return resul;
}

//-------------------------

bool Imagen::escribir_imagen(const char file[]){
	if (EscribirImagenPGM(file, buffer, filas, columnas))
		return true;
	return false;
}
