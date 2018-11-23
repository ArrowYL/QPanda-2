/*
Copyright (c) 2017-2018 Origin Quantum Computing. All Right Reserved.
Licensed under the Apache License 2.0

QProgToQASM.h
Author: Yulei
Created in 2018-7-19

Classes for Travesing QProg QGates as string use QASM instruction set .

Update@2018-8-31
update comment

*/
#ifndef  _QPROGTOQASM_H_
#define  _QPROGTOQASM_H_

#include "QuantumCircuit/QProgram.h"
#include <map>
#include "QuantumCircuit/QGlobalVariable.h"
#include "TransformDecomposition.h"
#include "QPanda/MetadataValidity.h"
using std::map;
using std::vector;

/*
Travesal QProg print QGates us QASM instruction set
*/
class QProgToQASM 
{
public:
    QProgToQASM();
     virtual ~QProgToQASM();

     /*
     overload operator <<
     param:
     out: output stream
     prog: QProg
     return:
     output stream
     Note:
     None
     */
     friend ostream & operator<<(ostream & out, const QProgToQASM &qasm_qprog);

     /*
     out insturctionsQASM
     param:
     return:
     string

     Note:
     None
     */
     string insturctionsQASM();

     /*
     Traversal QProg to instructions
     param:
     pQpro: AbstractQuantumProgram pointer
     return:
     None

     Note:
     None
     */
     void qProgToQasm(AbstractQuantumProgram *pQpro);

     /*
     Traversal QProg to instructions
     param:
     pQpro: AbstractQuantumProgram pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(AbstractQuantumProgram *pQpro);

     /*
     QGate to QASM instruction
     param:
     pGate: AbstractQGateNode pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(AbstractQGateNode *pQGata);

     /*
     Traversal QProg to instructions
     param:
     pCtrFlow: AbstractQuantumProgram pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(AbstractControlFlowNode *pCtrFlow);

     /*
     handleIfWhileQASM
     param:
     pCtrFlow: AbstractQuantumProgram pointer
     return:
     None

     Note:
     None
     */
     void handleIfWhileQASM(AbstractControlFlowNode * pCtrFlow, string ctrflowtype);

     /*
     Traversal QCircuit to QASM instructions
     param:
     pQpro: AbstractQuantumCircuit pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(AbstractQuantumCircuit *pCircuit);

     /*
     QMeasure to QASM instruction
     param:
     pMeasure: AbstractQuantumMeasure pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(AbstractQuantumMeasure *pMeasure);

     /*
     handleDaggerQASM
     param:
     pNode: QNode pointer
     return:
     None

     Note:
     None
     */
     void handleDaggerQASM(QNode * pNode, int nodetype);

     /*
     Traversal Dagger Circuit to QASM
     param:
     pNode: QNode pointer
     return:
     None

     Note:
     None
     */
     void qDaggerCirToQASM(QNode *pNode);
     
     /*
     Traversal QNode to QASM
     param:
     pNode: QNode pointer
     return:
     None

     Note:
     None
     */
     void qProgToQASM(QNode * pNode);

private:
    map<int, string>  m_gatetype_majuscule;
    map<int, string>  m_gatetype_qasm;

    vector<string> m_qasm;
};

#endif
