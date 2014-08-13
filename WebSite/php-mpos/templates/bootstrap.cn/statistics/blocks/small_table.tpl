  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-th fa-fw"></i> 最近发现的块
      </div>
      <div class="panel-body no-padding table-responsive">
        <table class="table table-striped table-bordered table-hover">
          <thead>
            <tr>
              <th>区块</th>
              <th>发现者</th>
              <th>时间</th>
              <th class="text-right">实际股份</th>
            </tr>
          </thead>
          <tbody>
{assign var=rank value=1}
{section block $BLOCKSFOUND}
            <tr>
              {if ! $GLOBAL.website.blockexplorer.disabled}
              <td><a href="{$GLOBAL.website.blockexplorer.url}{$BLOCKSFOUND[block].blockhash}" target="_new">{$BLOCKSFOUND[block].height}</a></td>
              {else}
              <td>{$BLOCKSFOUND[block].height}</td>
              {/if}
              <td>{if $BLOCKSFOUND[block].is_anonymous|default:"0" == 1 && $GLOBAL.userdata.is_admin|default:"0" == 0}anonymous{else}{$BLOCKSFOUND[block].finder|default:"unknown"|escape}{/if}</td>
              <td>{$BLOCKSFOUND[block].time|date_format:"%d/%m %H:%M:%S"}</td>
              <td class="text-right">{$BLOCKSFOUND[block].shares|number_format}</td>
            </tr>
{/section}
          </tbody>
        </table>
      </div>
{if $GLOBAL.config.payout_system != 'pps'}
      <div class="panel-footer">
          <h6>温馨提示: 需要耐心等待 <font class="confirmations">{$GLOBAL.confirmations}</font> 个确认后才能入账.</h6>
      </div>
{/if}
    </div>
  </div>
