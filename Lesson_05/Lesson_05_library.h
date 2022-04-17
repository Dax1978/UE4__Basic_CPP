#pragma once

#ifdef LESSON_05_LIBRARY_EXPORTS
#define LESSON_05_LIBRARY_API __declspec(dllexport)
#else
#define LESSON_05_LIBRARY_API __declspec(dllimport)
#endif

extern "C" LESSON_05_LIBRARY_API void printMassiveDouble(int n, double* massive);
extern "C" LESSON_05_LIBRARY_API void printMassiveInt(int n, int* massive);
extern "C" LESSON_05_LIBRARY_API void change1and0massive(int n, int* massive);
extern "C" LESSON_05_LIBRARY_API void fillMassiveThrough3(int n, int* massive);
extern "C" LESSON_05_LIBRARY_API void offsetMassive(int n, int* arr, int offset);
extern "C" LESSON_05_LIBRARY_API bool equalMassive(int n, int* arr);
extern "C" LESSON_05_LIBRARY_API void enterMassive(int n, int* arr);