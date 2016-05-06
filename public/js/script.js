
$(document).ready(function(){
    var fn = function(){

        //Ajax temperatura
        $.ajax({
            url: 'http://192.168.206.55/temp_c', //pega url para requisiçãos
            method :'GET',
            dataType : 'html', //dados vindos do servidor

            //se ouver successo na requisição
            success:function(html){
                $("#temperatura").html(html);
            },

            //se ouver erro na requisição
            error : function(xhr, status) {
                //alert('Erro na requisição ajax');
            },


            //se a requisição estiver completa
            complete : function(xhr, status) {
                console.log("Temperatura");
            }

        });


        $.ajax({
            url: 'http://192.168.206.55/heatindex', //pega url para requisiçãos
            method :'GET',
            dataType : 'html', //dados vindos do servidor

            //se ouver successo na requisição
            success:function(html){
                $("#humidade").html(html);
            },

            //se ouver erro na requisição
            error : function(xhr, status) {
                //alert('Erro na requisição ajax');
            },


            //se a requisição estiver completa
            complete : function(xhr, status) {
                console.log("Humidade");
            }

        });

    }

    var fn2 = function(){
        $.ajax({
            url: 'http://192.168.206.55/', //pega url para requisiçãos
            method :'GET',
            crossOrigin: true,
            data: null,
            dataType: 'html',
            success:function(html){
                $("#controle").html(html);
            },

            //se ouver erro na requisição
            error : function(xhr, status) {
                //alert('Erro na requisição ajax');
            },


            //se a requisição estiver completa
            complete : function(xhr, status) {
                console.log("controle");
            }

        });
    }



    setInterval(function(){
        fn();
        //fn2();
    },1000);

    fn();
    fn2();
    //event(onload,fn());
});



