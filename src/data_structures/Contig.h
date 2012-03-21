/*
 * Contig.h
 *
 *  Created on: Jan 25, 2012
 *      Author: vezzi
 */

#ifndef CONTIG_H_
#define CONTIG_H_

using namespace std;


#include "data_structures/Features.h"
#include "samtools/sam.h"
#include "options/Options.h"
#include "common.h"




class ContigsFeat{
public:
	unsigned int feature;
	vector<pair<unsigned int, unsigned int> > startStopPositions;
	ContigsFeat();

	~ContigsFeat();

};

enum data {readCov, insertCov, cmCov, woCov, wdCov, singCov, mdcCov};

class Position {
public:
	unsigned int ReadCoverage;
	unsigned int StratingInserts;
	unsigned int InsertCoverage;
	unsigned int CorrectlyMated;
	unsigned int WronglyOriented;
	unsigned int WronglyDistance;
	unsigned int Singleton;
	unsigned int MatedDifferentContig;
	unsigned long int insertsLength;

	Position();

	~Position();

};


#define MIN(x,y) \
  ((x) < (y)) ? (x) : (y)

class Contig{
	unsigned int contigLength;
	unsigned int minInsert;
	unsigned int maxInsert;
	unsigned int windowSize;
	unsigned int windowStep;

	float lowCoverageFeat;
	float highCoverageFeat;
	float lowNormalFeat;
	float highNormalFeat;
	float highSingleFeat;
	float highSpanningFeat;
	float highOutieFeat;

	Position *CONTIG;

	void updateCov(unsigned int strat, unsigned int end, data type);

public:
	Contig();
	Contig(unsigned int contigLength, unsigned int minInsert, unsigned int maxInsert);
	~Contig();

	void updateContig(bam1_t* b); // given an alignment it updates the contig situation


	unsigned int getLowCoverageAreas(float C_A);
	unsigned int getHighCoverageAreas(float C_A);
	unsigned int getLowNormalAreas(float C_M);
	unsigned int getHighNormalAreas(float C_M);
	unsigned int getHighSingleAreas();
	unsigned int getHighSpanningAreas();
	unsigned int getHighOutieAreas();
	unsigned int getCompressionAreas(float insertionMean, float insertionStd);
	unsigned int getExpansionAreas(float insertionMean, float insertionStd);

	void print();


	unsigned int getLowCoverageAreasZones(float C_A);
	unsigned int getHighCoverageAreasZones(float C_A);
	unsigned int getLowNormalAreasZones(float C_M);
	unsigned int getHighNormalAreasZones(float C_M);
	unsigned int getHighSingleAreasZones();
	unsigned int getHighSpanningAreasZones();
	unsigned int getHighOutieAreasZones();
	unsigned int getCompressionAreasZones(float insertionMean, float insertionStd, float Zscore);
	unsigned int getExpansionAreasZones(float insertionMean, float insertionStd, float Zscore);

	vector<pair<unsigned int, unsigned int> > lowCoverageAreas;
	vector<pair<unsigned int, unsigned int> > highCoverageAreas;
	vector<pair<unsigned int, unsigned int> > lowNormalAreas;
	vector<pair<unsigned int, unsigned int> > highNormalAreas;
	vector<pair<unsigned int, unsigned int> > highSingleAreas;
	vector<pair<unsigned int, unsigned int> > highSpanningAreas;
	vector<pair<unsigned int, unsigned int> > highOutieAreas;
	vector<pair<unsigned int, unsigned int> > compressionAreas;
	vector<pair<unsigned int, unsigned int> > expansionAreas;

};





#endif /* CONTIG_H_ */
