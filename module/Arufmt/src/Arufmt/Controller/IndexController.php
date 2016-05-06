<?php

namespace Arufmt\Controller;

use Zend\Mvc\Controller\AbstractActionController;
use Zend\View\Model\ViewModel;

use Arufmt\Model\GravaTable as ModelGravaTable;

class IndexController extends AbstractActionController
{

    public function indexAction()
    {
        return (new ViewModel())
            ->setTerminal($this->getRequest()->isXmlHttpRequest());
    }

    public function aumentarAction()
    {
        return (new ViewModel())
        ->setTerminal($this->getRequest()->isXmlHttpRequest());
    }

    public function gravarAction(){
        $temp =  $this->params()->fromRoute('temp',0);
        $hum =  $this->params()->fromRoute('hum',0);
        //echo "Temperatura: ".$temp."<br>";
        //echo "Humidade: ".$hum."<br>";
        $data = [
            'temp' => $temp,
            'hum' => $hum,
        ];
        $this->getGravaTable()->gravar($data);
        $resultado = $this->getGravaTable()->relatorio();

        return new ViewModel(['resultado' => $resultado]);
    }

    public function relatorioAction(){
        $temp =  $this->params()->fromRoute('temp',0);
        $hum =  $this->params()->fromRoute('hum',0);
        //echo "Temperatura: ".$temp."<br>";
        //echo "Humidade: ".$hum."<br>";

        $resultado = $this->getGravaTable()->relatorio();

        return new ViewModel(['resultado' => $resultado]);
    }


    public function getGravaTable()
    {
        $tableGateway = $this->getServiceLocator()->get('GravaTableGateway');
        return new ModelGravaTable($tableGateway);
    }

}
