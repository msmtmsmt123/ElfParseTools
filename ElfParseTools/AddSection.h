#include"ElfHeader.h"
#include"ProgramHeader.h"
#include"SectionHeader.h"
#include<vector>
#include"Windows.h"
using namespace std;
class AddSection
{
public:
	AddSection();
	~AddSection();
public:
	long iSectionHeaderOffset;
	short sStringSectionTableIndex;
	long iStringSectionOffset;
	int iFristLoadIndex;
	int iLastLoadIndex;
	long iAddSectionStartAddr = 0;//��Ӷν�����ʼ�ĵ�ַ
	int iNewSectionNameLen = 0;//���section�����ֵĳ���
	int iNewSectionSize = 0;//�����ӵ�Section�Ĵ�С
	int ireadSrcFileSize = 0;//��ȡ��Դ�ļ���С
	int iAddsectionAfterFileSize = 0;//���ӽ���ͷ֮����ļ���С
	int iFinalFileSize = 0;//���յ��ļ���С
	char * p_cNewSectionName;
	char * p_cSrcFilePath;//Դ�ļ�·��
public:
	void initParameter_32(ElFHeader_32 elfHeader_32, vector<ProgramHeader_32> programHeaderVector_32,vector<SectionHeader_32> sectionHeaderVector_32);
	void initParameter_64(ElFHeader_64 elfHeader_64, vector<ProgramHeader_64> programHeaderVector_64, vector<SectionHeader_64> sectionHeaderVector_64);
	char* addSectionHeader(char *p_cSrc,int type);
	char* adSectionForFileEnd(char *p_cSrc);
	char* chageStrTabLen(char *p_cSrc,int type);
	char* changeElfHeaderSectionCount(char *p_Src,int type);
	void changeProgramHeaderLoadInfo(char *p_cSrc,int type);
	long alignOffset(long addr, long align);
};

