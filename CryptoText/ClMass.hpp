#ifndef CLMASS_H
#define CLMASS_H
template<typename X>
void ClMass(X *mass)
{
	for (int i = 0; i < 80; i++) mass[i] = 0;
}
template<typename X>
void ClMass(X *mass, int range)
{
	for (int i = 0; i < range; i++) mass[i] = 0;
}
#endif