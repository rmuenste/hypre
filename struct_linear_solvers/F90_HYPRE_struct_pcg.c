/*BHEADER**********************************************************************
 * (c) 1998   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/

#include "headers.h"
#include "fortran.h"

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGInitialize
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcginitialize)( int      *comm,
                                            long int *solver,
                                            int      *ierr   )

{
   *ierr = (int) ( HYPRE_StructPCGInitialize( (MPI_Comm)             *comm,
                                              (HYPRE_StructSolver *) solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGFinalize
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_structpcgfinalize)( long int *solver,
                                          int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGFinalize( (HYPRE_StructSolver) *solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetup
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_structpcgsetup)( long int *solver,
                                       long int *A,
                                       long int *b,
                                       long int *x,
                                       int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGSetup( (HYPRE_StructSolver) *solver,
                                         (HYPRE_StructMatrix) *A,
                                         (HYPRE_StructVector) *b,
                                         (HYPRE_StructVector) *x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSolve
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_structpcgsolve)( long int *solver,
                                       long int *A,
                                       long int *b,
                                       long int *x,
                                       int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGSolve( (HYPRE_StructSolver) *solver,
                                         (HYPRE_StructMatrix) *A,
                                         (HYPRE_StructVector) *b,
                                         (HYPRE_StructVector) *x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetTol
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsettol)( long int *solver,
                                        double   *tol,
                                        int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGSetTol( (HYPRE_StructSolver) *solver,
                                          (double)             *tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetMaxIter
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsetmaxiter)( long int *solver,
                                            int      *max_iter,
                                            int      *ierr     )
{
   *ierr = (int) ( HYPRE_StructPCGSetMaxIter( (HYPRE_StructSolver) *solver,
                                              (int)                *max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetTwoNorm
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsettwonorm)( long int *solver,
                                            int      *two_norm,
                                            int      *ierr     )
{
   *ierr = (int) ( HYPRE_StructPCGSetTwoNorm( (HYPRE_StructSolver) *solver,
                                              (int)                *two_norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetRelChange
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsetrelchange)( long int *solver,
                                              int      *rel_change,
                                              int      *ierr       )
{
   *ierr = (int) ( HYPRE_StructPCGSetRelChange( (HYPRE_StructSolver) *solver,
                                                (int)                *rel_change ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetPrecond
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsetprecond)( long int *solver,
                                            int      *precond_id,
                                            long int *precond_solver,
                                            int      *ierr           )
{

   /*------------------------------------------------------------
    * The precond_id flags mean :
    * 0 - setup a smg preconditioner
    * 1 - setup a pfmg preconditioner
    * 8 - setup a ds preconditioner
    * 9 - dont setup a preconditioner
    *------------------------------------------------------------*/

   if (*precond_id == 0)
   {
      *ierr = (int) ( HYPRE_StructPCGSetPrecond( (HYPRE_StructSolver) *solver,
                                                 HYPRE_StructSMGSolve,
                                                 HYPRE_StructSMGSetup,
                                                 (HYPRE_StructSolver) *precond_solver) );
   }
   else if (*precond_id == 1)
   {
      *ierr = (int) ( HYPRE_StructPCGSetPrecond( (HYPRE_StructSolver) *solver,
                                                 HYPRE_StructPFMGSolve,
                                                 HYPRE_StructPFMGSetup,
                                                 (HYPRE_StructSolver) *precond_solver) );
   }
   else if (*precond_id == 8)
   {
      *ierr = (int) ( HYPRE_StructPCGSetPrecond( (HYPRE_StructSolver) *solver,
                                                 HYPRE_StructDiagScale,
                                                 HYPRE_StructDiagScaleSetup,
                                                 (HYPRE_StructSolver) *precond_solver) );
   }
   else if (*precond_id == 9)
   {
      *ierr = 0;
   }
   else
   {
      *ierr = -1;
   }
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGSetLogging
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcgsetlogging)( long int *solver,
                                            int      *logging,
                                            int      *ierr    )
{
   *ierr = (int) ( HYPRE_StructPCGSetLogging( (HYPRE_StructSolver) *solver,
                                              (int)                *logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGGetNumIterations
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcggetnumiterations)( long int *solver,
                                                  int      *num_iterations,
                                                  int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGGetNumIterations( (HYPRE_StructSolver) *solver,
                                                    (int *)              num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructPCGGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_structpcggetfinalrelative)( long int *solver,
                                                  double   *norm,
                                                  int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructPCGGetFinalRelativeResidualNorm( (HYPRE_StructSolver) *solver,
                                                                (double *)           norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructDiagScaleSetup
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_structdiagscalesetup)( long int *solver,
                                             long int *A,
                                             long int *y,
                                             long int *x,
                                             int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructDiagScaleSetup( (HYPRE_StructSolver) *solver,
                                               (HYPRE_StructMatrix) *A,
                                               (HYPRE_StructVector) *y,
                                               (HYPRE_StructVector) *x      ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_StructDiagScale
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_structdiagscale)( long int *solver,
                                        long int *HA,
                                        long int *Hy,
                                        long int *Hx,
                                        int      *ierr   )
{
   *ierr = (int) ( HYPRE_StructDiagScale( (HYPRE_StructSolver) *solver,
                                          (HYPRE_StructMatrix) *HA,
                                          (HYPRE_StructVector) *Hy,
                                          (HYPRE_StructVector) *Hx     ) );
}
