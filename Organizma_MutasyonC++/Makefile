all:derle bagla calistir
derle:

	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/SatirHucre.cpp -o ./lib/SatirHucre.o
	g++ -c -I "./include" ./src/OrganizmaDugum.cpp -o ./lib/OrganizmaDugum.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/SatirDoku.cpp -o ./lib/SatirDoku.o
	g++ -c -I "./include" ./src/Radixon_f.cpp -o ./lib/Radixon_f.o
	g++ -c -I "./include" ./src/OrganDugum.cpp -o ./lib/OrganDugum.o	
	g++ -c -I "./include" ./src/Dugum_ikili_agac_arama.cpp -o ./lib/Dugum_ikili_agac_arama.o
	g++ -c -I "./include" ./src/OrganListesi.cpp -o ./lib/OrganListesi.o
	g++ -c -I "./include" ./src/SistemDugum.cpp -o ./lib/SistemDugum.o
	g++ -c -I "./include" ./src/SistemListesi.cpp -o ./lib/SistemListesi.o	
	g++ -c -I "./include" ./src/IkiliArama_agaci.cpp -o ./lib/IkiliArama_agaci.o
	

	
bagla:
	g++	  ./lib/SatirDoku.o  ./lib/OrganDugum.o ./lib/OrganizmaDugum.o ./lib/Organizma.o ./lib/SistemListesi.o ./lib/SistemDugum.o ./lib/IkiliArama_agaci.o ./lib/OrganListesi.o ./lib/Dugum_ikili_agac_arama.o ./lib/SatirHucre.o ./lib/Radixon_f.o ./lib/main.o  -o ./bin/program
calistir:
	./bin/program