<?php
namespace Arufmt\Model;

class Grava
{
    public $id;
    public $temp;
    public $hum;

    public function exchangeArray($data){
        $this->id = (isset($data['id']) ? $data['id'] : null);
        $this->temp = (isset($data['temp']) ? $data['temp'] : null);
        $this->hum = (isset($data['hum']) ? $data['hum'] : null);
        $this->data_hora = (isset($data['data_hora']) ? $data['data_hora'] : null);
    }
}