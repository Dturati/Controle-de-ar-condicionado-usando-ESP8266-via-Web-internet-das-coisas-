<?php
namespace Arufmt\Model;

use Zend\Db\Adapter\Adapter;
use Zend\Db\ResultSet\ResultSet;
use Zend\Db\TableGateway\TableGateway;
use Zend\Db\Sql\Select;

class GravaTable
{
    protected $tableGateway;

    public function __construct(TableGateway $tableGateway){
        return $this->tableGateway = $tableGateway;
    }

    public function gravar($data){
        $timeNow = new \DateTime();
        $dados = [
            'temp'          => $data['temp'],
            'hum'           => $data['hum'],
            'data_hora'     => $timeNow->format('Y-m-d H:i:s'),
        ];

        $this->tableGateway->insert($dados);
    }

    public function relatorio()
    {
        /*
        //echo "Relatorio";
        $resultSet = $this->tableGateway->select();

        return $resultSet->current();
        */
        $select = new Select();
        $select->from('temphum');
        $resultSet = $this->tableGateway->selectWith($select);
       return $resultSet;
    }
}