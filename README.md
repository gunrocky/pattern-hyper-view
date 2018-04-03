# pattern-hyper-view
Implement a system (mock system, without implementation details) for managing virtual machines on hypervisors (ESXi, HyperV, SCVMM, Physical PC). The system should be able to: create a new virtual machine with parameters (CPU, RAM, HDD, OS selection), clone an existing one, delete, and install applications. Also display task progress.

Patterns used:
* Prototype - used to clone a virtual machine in CHyperVVirtM::CloneVM
* Observer - used to display the progress of creating and cloning a virtual machine in CHyperVVirtM constructors.
