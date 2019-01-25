## Stochastic Rotation Dynamics

Stochastic Rotation Dynamics (SRD) introduced by Malevanets and Kapral is a widely used simulation method for the particle-based
numerical simulation of fluids; thus, SRD belongs to the class of particle-based methods for computational fluid dynamics (CFD)
simulations. In comparison with traditional lattice-based CFD, particle-based methods reveal a number of interesting features,
which are of advantage in certain domains of fluid mechanics, in particular, for applications  where  thermal  fluctuations  are
important. SRD was successfully  applied  to  simulations  of  polymers, suspensions of self-propelled particles, dynamics of
membranes, and living cells.

By now, there is a large number of variants and extensions of the original SRD scheme regarding incorporation of physical
properties such as nonideal equations of  state, immiscible  fluids, angular  momentum  conservation, surface wettability,
and isotropic collision rule. Recent reviews on SRD and its applications can be found in:

* R.  Kapral,  “Multiparticle  collision  dynamics:  Simulation  of  complex systems on mesoscales,” Adv. Chem. Phys.
140, 89 (2008).

* G.  Gompper,  T.  Ihle,  D.  M.  Kroll,  and  R.  G.  Winkler,  “Multi-particle collision  dynamics:  A  particle-based  mesoscale
simulation  approach  to the hydrodynamics of complex fluids,” in Advanced Computer Simulation Approaches for Soft Matter Sciences
III, edited by C. Holm and K. Kremer (Springer Berlin Heidelberg, Berlin, Heidelberg, 2009), pp. 1–87.

## The code
The code that is presented here, contains the basics of SRD method. You can develop it further for your own application. I also
recommend to read this article about the limitations of this particle based method:

* Shakeri, Ali, Kuang-Wu Lee, and Thorsten Pöschel. "Limitation of stochastic rotation dynamics to represent hydrodynamic
interaction between colloidal particles." Physics of Fluids 30.1 (2018): 013603.
