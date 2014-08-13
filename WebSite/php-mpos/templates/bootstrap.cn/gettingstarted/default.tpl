 <div class="row">
    <div class="col-lg-12">
      <div class="panel panel-info">
        <div class="panel-heading">
          <i class="fa fa-question fa-fw"></i> 挖矿指南
        </div>
        <div class="panel-body">
        
    <p>1. <strong>创建账号.</strong></p>
      <ul>
        <li>请先 <a href="{$smarty.server.SCRIPT_NAME}?page=register">注册账号</a>, 如果已有帐号请<a href="{$smarty.server.SCRIPT_NAME}?page=login">登陆</a></li>
        <li>添加一个或多个 <a href="{$smarty.server.SCRIPT_NAME}?page=account&action=workers">矿工</a> 用于挖矿程序的登陆</li>
      </ul>
    </li>
    <p>2. <strong>下载采矿程序</strong></p>
      <ul>
        <li><em>Intel/ATI/AMD CGMiner Windows Sha256:</em> <a href="http://ck.kolivas.org/apps/cgminer/cgminer-4.2.2-windows.zip" target="_blank"> 点击下载</a></li>
        <li><em>Intel/ATI/AMD CGMiner Linux Sha256:</em> <a href="http://ck.kolivas.org/apps/cgminer/cgminer-4.2.2.tar.bz2" target="_blank"> 点击下载</a></li>
	<li><em>Intel/ATI/AMD CGMiner 3.7.2 Scrypt Windows:</em> <a href="https://mega.co.nz/#!iQhlGIxa!mzKOfLY6TpOfvPvWE6JFlWdRgHEoshzm99f1hd3ZdRw" target="_blank"> 点击下载</a></li>	
	<li><em>Intel/ATI/AMD CGMiner 3.7.2 Scrypt Linux:</em> <a href="http://ck.kolivas.org/apps/cgminer/3.7/cgminer-3.7.0.tar.bz2" target="_blank"> 点击下载</a></li>	
	<li><em>Intel/ATI/AMD BFGMiner Linux/Windows:</em> <a href="http://bfgminer.org" target="_blank"> 点击下载</a></li>
        <li><em>Fabulous Panda Miner Mac OS X:</em> <a href="http://fabulouspanda.co.uk/macminer/" target="_blank"> 点击下载</a></li>
        <li><em>Minerd CPU Miner Mac/Linux/Windows:</em><a href="https://bitcointalk.org/index.php?topic=55038.msg654850#msg654850" target="_blank"> 点击下载</a>.</li>
        <li><em>NVIDIA Cudaminer:</em><a href="https://mega.co.nz/#!ZQxxRKJI!W_H00CQCBdQZUpgokQWmAsteplcbQfc-j44LrAvM9oQ" target="_blank"> 点击下载</a></li>
	  </ul>
    </li>
    <p>3. <strong>配置采矿程序</strong></p>
    <ul>
      <p>如果你使用Linux系统,请输入以下到控制台:</p>
      <li>CGMiner</li>
      <pre>./cgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>BFGMiner</li>
      <pre>./bfgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <br />
	  <p> 如果您想在 <strong> Windows Operating System </strong>操作系统上挖掘, 那么你就需要创建一个批处理文件来启动你的挖矿程序. </p><p> 你可以在 <a href="https://mega.co.nz/#F!zdB3iDgS!MQfawuzu0FoEQ6sDEJSLnQ" target="_blank">这里</a> 下载预配置的一个或你可以让你自己打开记事本，然后复制和粘贴</p>
	  <li>MinerD</li>
      <pre>minerd -a {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -t 6 -s 4 -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>CGMiner</li>
      <pre>cgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>BFGMiner</li>
      <pre>bfgminer {if $GLOBAL.config.algorithm == 'scrypt'}--scrypt{/if} -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
      <li>Cudaminer For NVIDIA Cards</li>
	  <pre>cudaminer -o stratum+tcp://{$SITESTRATUMURL|default:$smarty.server.SERVER_NAME}:{$SITESTRATUMPORT|default:"3333"} -u <em>Weblogin</em>.<em>WorkerName</em> -p <em>WorkerPassword</em></pre>
	  <br />
	  <p> 然后，您需要更改“-u Weblogin.Worker -p Worker password" 为您自己的矿工号 和 矿工密码, 例如："-u username.001 -p 123456" 然后进入 "文件 => 另存为" 将文件保存为 "RunMe.bat" 需要保存跟您的挖矿程序同个目录下. 您现在可以开采，双击“RunMe.bat”开始挖掘。如果你需要创建更多的矿工与您所选择的用户名和密码, 请点击<a href="{$smarty.server.SCRIPT_NAME}?page=account&action=workers">这里。</a></p>
    </ul>
    <p>4. <strong>创建您的 {$SITECOINNAME|default:"Litecoin"} 收款钱包地址.</strong></p>
      <ul>
        <li> 下载钱包客户端: 下载 {$SITECOINNAME|default:"Litecoin"} 客户端 <a href="{$SITECOINURL|default:"http://www.litecoin.org"}" target="_blank">点击这里</a>.
          <p>生成一个新的钱包地址，将新的收款地址输入在你的帐户页面收款地址上.</p>
        </li>
      </ul>
    </li>
    <p>5. <strong>高级 cgminer 设置 / 常见问题</strong></p>
      <ul>
        <li><a href="https://raw.github.com/ckolivas/cgminer/v3.7.2/SCRYPT-README" target="_blank">Scrypt readme</a></li>
        <li>Don't set <b>intensity</b> too high, I=11 is standard and safest. Higher intensity takes more GPU RAM. Check for <b>hardware errors</b> in cgminer (HW). HW=0 is good, otherwise lower intensity :)</li>
        <li>Set shaders according to the readme (or look at your graphic cards specifications). Cgminer uses this value at first run to calculate <b>thread-concurrency</b>. Easiest way to get this optimized is to use same settings as others have used here: <a href="http://litecoin.info/Mining_Hardware_Comparison" target="_blank">here</a>.</li>
        <li>There's also an interesting project which gives you a GUI for cgminer. Windows only it seems.</li>
        <li>Here's a great <a href="https://docs.google.com/document/d/1Gw7YPYgMgNNU42skibULbJJUx_suP_CpjSEdSi8_z9U/preview?sle=true" target="_blank">guide</a> how to get up and running with Xubuntu.</li>
      </ul>
    </li>
        </div>
      </div>
    </div>
    <!-- /.col-lg-12 -->
  </div>
