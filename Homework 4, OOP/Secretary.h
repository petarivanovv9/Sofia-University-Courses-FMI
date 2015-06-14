#pragma once

class Secretary {
public:
	Secretary();
	Secretary(const Secretary& other);
	Secretary& operator=(const Secretary& other);
	~Secretary();
public:
	void addLanguage(char*);
public:
	char** getLanguages() const;
	int getNumberLanguages() const;
	void printSecretary() const;
private:
	void clearSecretary();
	void copySecretary(const Secretary& other);
private:
	char** languages;
	int numberLanguages;
};