#ifndef _GA_H
#define _GA_H 1

#define NMAX 250
#define PMAX 1024

// Individual
typedef struct {
  // Chromosome representation
  double *value;
  int    *chromo;
  int    nParams;
  int    nPrec;
  double fitness;
  int    rank;
  int    encoded;
} Individual;

// Population
typedef struct {
  Individual indiv[PMAX];
  Individual newph[PMAX];
  // index gives each entry in increasing order of fitness [0 to np-1]
  int index[PMAX];
} Population;

typedef struct {
  // Elite option
  int iElite;
  // Number of fit parameters
  int nParams;
  //Number of individuals in population
  int np;
  // Encoding constant
  int nd;
  // Cross probability
  double pCross;
  // Mutation probability
  double pMutate;
  // Number of generations
  int nGenerations;
  // Mutation probability adjustment parameter
  int iMutate;
  double pMutateMin;
  double pMutateMax;
  double fitnessSlope;
  // Fitness function
  double (*function)(int n, const double*v, void*p);
  void *funcParms;
  int popOption;
  int algo_type;
  int initOption;
  char popFile[64];
  // Data
  Population *pop;
  int genNumber;
  // Write population ever X generations.
  int trace_period;
  int trace_overwrite;
  // Add to the report every generation. 
  int print_stats;
} Settings;

/** Random number generator */
double frandom();

/** get/set chromosomes */
/** Find the fittest individual */
double getChromosome(Settings *set, int n, double *d);
void setChromosome(Settings *set, int n, double *d);
int fittest(Settings *set);

/** Perform fit */
void ga_init( Settings *set, double *params );
double ga_fit( Settings *set, int nGenerations );

/** Read and write population */
int write_pop_backup( Settings *set);
int write_pop( Settings *set);
int read_pop( Settings *set, const char *file);

void initSettings( Settings *set );
void randomizePop( Settings *set, int par );
int GetGen( Settings *set );

/** Sets a parameter to a given value for all members of the current population */
void setParValue( Settings *set, int ipar, double value);
void setRange( Settings *set, int ipar, double oldmin, double oldrange,
                double newmin, double newrange );
#endif
