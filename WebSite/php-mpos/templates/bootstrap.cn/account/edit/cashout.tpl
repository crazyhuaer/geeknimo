{if !$GLOBAL.config.disable_payouts && !$GLOBAL.config.disable_manual_payouts}
<form action="{$smarty.server.SCRIPT_NAME}" method="post" role="form">
  <input type="hidden" name="page" value="{$smarty.request.page|escape}">
  <input type="hidden" name="action" value="{$smarty.request.action|escape}">
  <input type="hidden" name="do" value="cashOut">
  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-money fa-fw"></i> 手动取币
      </div>
      <div class="panel-body">
        <div class="row">
          <div class="col-lg-12">
            <div class="form-group">
              <p style="padding-left:3px; padding-redight:30px; font-size:10px;">
                提示: 手动提现将扣除手续费 {if $GLOBAL.config.txfee_manual > 0.00001}{$GLOBAL.config.txfee_manual}{else}{$GLOBAL.config.txfee_manual|number_format:"8"}{/if} {$GLOBAL.config.currency}  <span id="tt"><img width="15px" height="15px" title="This {if $GLOBAL.config.txfee_manual > 0.00001}{$GLOBAL.config.txfee_manual}{else}{$GLOBAL.config.txfee_manual|number_format:"8"}{/if} 该收费是TX网络收取，不是本池所需收取费用" src="site_assets/mpos/images/questionmark.png"></span>
              </p>
              <p style="padding-left:3px; padding-redight:30px; font-size:10px;">
                最低取币数: {$GLOBAL.config.mp_threshold} {$GLOBAL.config.currency}
              </p>
            </div>
            <div class="form-group">
              <label>账户余额</label>
              {nocache}<input class="form-control" id="disabledInput" type="text" value="{$GLOBAL.userdata.balance.confirmed|escape}" {$GLOBAL.config.currency} disabled />{/nocache}
            </div>
            <div class="form-group">
              <label>支付地址</label>
              {nocache}<input class="form-control" id="disabledInput" type="text" value="{$GLOBAL.userdata.coin_address|escape}" disabled />{/nocache}
            </div>
            <div class="form-group">
              <label>4 数字取币PIN码</label>
              <input class="form-control" type="password" name="authPin" size="4" maxlength="4" />
            </div>
          </div>
        </div>
      </div>
      <div class="panel-footer">
      {nocache}
      <input type="hidden" name="wf_token" value="{$smarty.request.wf_token|escape|default:""}">
      <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}" />
      <input type="hidden" name="utype" value="withdraw_funds">
      {if $GLOBAL.twofactor.enabled && $GLOBAL.twofactor.options.withdraw}
      {if $GLOBAL.userdata.balance.confirmed|escape < $GLOBAL.config.mp_threshold}
      <input type="submit" value="Unlock" class="btn btn-warning btn-sm" name="unlock"  disabled="disabled">
      {elseif $WITHDRAWSENT == 1 && $WITHDRAWUNLOCKED == 1}
      <input type="submit" value="Cash Out" class="btn btn-success btn-sm">
      {elseif $WITHDRAWSENT == 0 && $WITHDRAWUNLOCKED == 1 || $WITHDRAWSENT == 1 && $WITHDRAWUNLOCKED == 0}
      <input type="submit" value="Cash Out" class="btn btn-danger btn-sm" disabled="disabled">
      {elseif $WITHDRAWSENT == 0 && $WITHDRAWUNLOCKED == 0}
      <input type="submit" value="Unlock" class="btn btn-warning btn-sm" name="unlock">
      {/if}
      {else}
      <input type="submit" value="确认取币" class="btn btn-success btn-sm">
      {/if}
      {/nocache}
      </div>
    </div>
  </div>
</form>
{/if}
